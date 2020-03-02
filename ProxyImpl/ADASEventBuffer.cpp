#include "ADASEventBuffer.h"

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
    //Register enum
    qRegisterMetaType<ADAS_GL_STATE>("ADAS_GL_STATE");

    //TODO (LYWOO) : connected
}

ADASEventBuffer::ADASEventBuffer(QObject* parent)
    : QObject(parent)
{
}
