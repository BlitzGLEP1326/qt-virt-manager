#include "control_thread.h"

ControlThread::ControlThread(QObject *parent) :
    _VirtThread(parent)
{
    qRegisterMetaType<Result>("Result");
    qRegisterMetaType<Actions>("Actions");
}

/* public slots */
bool ControlThread::setCurrentWorkConnect(
        virConnectPtr *_connPtrPtr, uint i, QString _name)
{
    keep_alive = true;
    number = i;
    currConnName = _name;
    ptr_ConnPtr = _connPtrPtr;
    // for new virConnect usage create the new virConnectRef[erence]
    int ret = virConnectRef(*ptr_ConnPtr);
    if ( ret<0 ) {
        ptr_ConnPtr = NULL;
        sendConnErrors();
        keep_alive = false;
    };
    //qDebug()<<"virConnectRef +1"<<"ControlThread"<<currConnName<<(ret+1>0)<<number;
    //qDebug()<<"net_thread"<<ptr_ConnPtr;
    return keep_alive;
}
void ControlThread::execAction(uint _number, TASK task)
{
    Q_UNUSED(_number); Q_UNUSED(task);
}
