#ifndef LAB_PROGRAMMAZIONE_OBSERVER_H
#define LAB_PROGRAMMAZIONE_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {};
    virtual void update() =0;
};


#endif //LAB_PROGRAMMAZIONE_OBSERVER_H
