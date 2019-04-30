#ifndef LAB_PROGRAMMAZIONE_SUBJECT_H
#define LAB_PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
protected:
    virtual ~Subject() {};

public:
    virtual void registerObserver (Observer *o) =0;
    virtual void removeObserver (Observer * o) =0;
    virtual void notifyObserver () const =0;
};

#endif //LAB_PROGRAMMAZIONE_SUBJECT_H
