#include "ADASEventBuffer.h"
#include <QDebug>
#define SIGNAL_TEST 1
#define FUNCTION_TEST 0

static QSharedPointer<ADASEventBuffer> gADASEventBufferIstance;

QSharedPointer<ADASEventBuffer> ADASEventBuffer::instance()
{
    if (gADASEventBufferIstance.isNull()) {
        gADASEventBufferIstance = QSharedPointer<ADASEventBuffer>(new ADASEventBuffer());
    }

    return gADASEventBufferIstance;
}

ADASEventBuffer::~ADASEventBuffer()
{
}

void ADASEventBuffer::init()
{
    qRegisterMetaType<ADAS_GL_STATE>("ADAS_GL_STATE");

    //TODO (LYWOO) : connected
}

void ADASEventBuffer::setAdasInfo(const v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& adasInfo)
{
    setNextADASInfo(adasInfo);

#if SIGNAL_TEST
    emit signalRequestGLState();
#endif

#if FUNCTION_TEST
    //TODO getGLState .....call slotReceivedGLState......
#endif
}

void ADASEventBuffer::getAdasInfo(v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo* adasInfo)
{
    //TODO (LYWOO) : changed arg type (StAdasInfo -> inner type)
    //TODO (LYWOO) : copy data ...
    adasInfo->setDisp_type(mCurrentADASInfo.getDisp_type());
}

void ADASEventBuffer::requestGLState()
{
    emit signalRequestGLDraw();
}

ADASEventBuffer::ADASEventBuffer(QObject* parent)
    : QObject(parent)
{
}

void ADASEventBuffer::setCurrentADASInfo(const v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& currentData)
{
    mCurrentADASInfo = currentData;
    setCurrentADASInfoValid();
}

v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& ADASEventBuffer::getCurrentADASInfo()
{
    return mCurrentADASInfo;
}

void ADASEventBuffer::setNextADASInfo(const v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& currentData)
{
    mNextADASInfo = currentData;
    setNextADASInfoValid();
}

v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& ADASEventBuffer::getNextADASInfo()
{
    return mNextADASInfo;
}

void ADASEventBuffer::setCurrentADASInfoValid()
{
    setCurrentADASInfoValid(true);
}

void ADASEventBuffer::setCurrentADASInfoInValid()
{
    setCurrentADASInfoValid(false);
}

void ADASEventBuffer::setNextADASInfoValid()
{
    setNextADASInfoValid(true);
}

void ADASEventBuffer::setNextADASInfoInValid()
{
    setNextADASInfoValid(false);
}

void ADASEventBuffer::setCurrentADASInfoValid(const bool isValid)
{
    mCurrentADASInfoValid = isValid;
}

void ADASEventBuffer::setNextADASInfoValid(const bool isValid)
{
    mNextADASInfoValid = isValid;
}

void ADASEventBuffer::slotReceivedGLState(ADAS_GL_STATE state)
{
    if ((ADAS_GL_STATE::ADAS_GL_READY == state) || (ADAS_GL_STATE::ADAS_GL_DRAW_COMPLETE == state)) {
        setCurrentADASInfoInValid();

        if (true == mNextADASInfoValid) {
            setCurrentADASInfo(getNextADASInfo());
            requestGLState();
        }
    } else {
        if (true == mNextADASInfoValid) {
            qDebug() << Q_FUNC_INFO << "GL Event Wait -  ADAS_GL_STATE::ADAS_GL_DRAW_COMPLETE signal wait";
        } else {
            qDebug() << Q_FUNC_INFO << "Mcu Event Wait";
        }
    }
}
