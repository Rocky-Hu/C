#include <stdio.h>
#include "jni.h"

// static JNINativeMethod methods[] = {
//     {"hashCode",    "()I",                    (void *)&JVM_IHashCode},
//     {"wait",        "(J)V",                   (void *)&JVM_MonitorWait},
//     {"notify",      "()V",                    (void *)&JVM_MonitorNotify},
//     {"notifyAll",   "()V",                    (void *)&JVM_MonitorNotifyAll},
//     {"clone",       "()Ljava/lang/Object;",   (void *)&JVM_Clone},
// };

int main()
{
    char *name;
    name = "hashCode";
    printf("%s\n", name);
    return 0;
}