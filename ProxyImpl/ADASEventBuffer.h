#ifndef ADASEVENTBUFFER_H
#define ADASEVENTBUFFER_H

#include "../ProxyImpl/ADASTypes.h"
#include "v1/proj/dcluster/McuManager/McuManagerProxy.hpp"
#include <QObject>
#include <QSharedPointer>
using MCUManagerType = v1::proj::dcluster::McuManager::McuManagerTypes;

class ADASEventBuffer : public QObject {

    Q_OBJECT

public:
    static QSharedPointer<ADASEventBuffer> instance();

    ~ADASEventBuffer();

    void init();

    //whith CommonAPI : [ this <- commonAPI ]
    void setAdasInfo(const MCUManagerType::StAdasInfo& adasInfo);

    //whith GL : [ this <- GL ]
    void getAdasInfo(MCUManagerType::StAdasInfo* adasInfo);

    //whith GL : [this -> GL]
    void requestGLState(); // signal

private:
    explicit ADASEventBuffer(QObject* parent = Q_NULLPTR);

    void setCurrentADASInfo(const MCUManagerType::StAdasInfo& currentData);
    MCUManagerType::StAdasInfo& getCurrentADASInfo();

    void setNextADASInfo(const MCUManagerType::StAdasInfo& currentData);
    MCUManagerType::StAdasInfo& getNextADASInfo();

    void clearCurrentData();
    void clearNextData();

private:
    MCUManagerType::StAdasInfo mCurrentADASInfo; // drawing data
    MCUManagerType::StAdasInfo mNextADASInfo; // buffer & draw wait data

signals:
    void signalRequestGLState();
    void signalRequestGLDraw();

public slots:
    void slotReceivedGLState(ADAS_GL_STATE state); // get value
};

#endif // ADASEVENTBUFFER_H
