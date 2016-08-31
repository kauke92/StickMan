#ifndef CLOUDCOLLECTION_H
#define CLOUDCOLLECTION_H

#include "cloud.h"

class CloudCollection
{
public:
    CloudCollection();
    ~CloudCollection();
    static CloudCollection *getCloudCollection();
    void add(Cloud c);
    void renderAll(QPainter &painter);
    int size() const;
    Cloud &get(int index);

private:
    static CloudCollection *cloudcollection;
    std::vector<Cloud> *cloudlist;
};

#endif // CLOUDCOLLECTION_H
