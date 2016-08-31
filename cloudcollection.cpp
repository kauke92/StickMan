#include "cloudcollection.h"
CloudCollection* CloudCollection::cloudcollection = 0;

CloudCollection* CloudCollection::getCloudCollection()
{
    if (cloudcollection == 0)
    {
        cloudcollection = new CloudCollection();
    }
    return cloudcollection;
}
CloudCollection::CloudCollection()
{
    cloudlist = new vector<Cloud>;
}

/*
 * add a new cloud to the collection
 */
void CloudCollection::add(Cloud c)
{
    cloudlist->push_back(c);
}

void CloudCollection::renderAll(QPainter &painter)
{
    for (int i = 0; i < (int) cloudlist->size(); i++)
    {
        cloudlist->at(i).render(painter);
    }
}

int CloudCollection::size() const
{
    return cloudlist->size();
}

Cloud &CloudCollection::get(int index)
{
    return cloudlist->at(index);
}

CloudCollection::~CloudCollection()
{
        delete cloudcollection;
        delete cloudlist;
}

