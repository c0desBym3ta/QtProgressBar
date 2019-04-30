#ifndef LAB_PROGRAMMAZIONE_CONCRETEOBSERVER_H
#define LAB_PROGRAMMAZIONE_CONCRETEOBSERVER_H

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(ResourcesLoader *resources_) : resources(resources_) {
        resources->registerObserver(this);
    }

    virtual ~ConcreteObserver() {
        resources->removeObserver(this);
    }

    virtual void update() override {}

    ResourcesLoader * resources;
};

#endif //LAB_PROGRAMMAZIONE_CONCRETEOBSERVER_H
