#ifndef OBJECTS_H
#define OBJECTS_H

class Objects
{
    public:
        //Game Objects BluePrint
            virtual void Draw() = 0;
            virtual void Update(float dt) = 0;
            virtual void Clean() = 0;
};

#endif