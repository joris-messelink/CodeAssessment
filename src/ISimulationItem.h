#ifndef ISIMULATIONITEM_H
#define ISIMULATIONITEM_H

class ISimulationItem 
{
public:
    virtual ~ISimulationItem() = default;
    virtual void update(int timeStep) = 0;
};

#endif /* ISIMULATIONITEM_H */
