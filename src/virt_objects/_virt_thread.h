#ifndef _VIRT_THREAD_H
#define _VIRT_THREAD_H

#include <QThread>
#include <QString>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>

class _VirtThread : public QThread
{
    Q_OBJECT
public:
    explicit _VirtThread(QObject *parent = NULL);
    virtual ~_VirtThread();
    bool             keep_alive;
    uint             number;
    virConnectPtr   *ptr_ConnPtr;
    virErrorPtr      virtErrors;

    virtual void     stop();
    virtual QString  sendConnErrors();
    virtual QString  sendGlobalErrors();

signals:
    virtual void     errorMsg(QString&, uint);
};

#endif // _VIRT_THREAD_H
