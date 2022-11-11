#include <raylib.h>

class GameObject
{
public:
    Rectangle srcRec;
    Rectangle screenRec;

    bool inWindow();
    bool collision(const GameObject& other);
};
