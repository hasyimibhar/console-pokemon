#include "Move.h"

Move::Move(std::string name, int maxPp)
: name(name), pp(maxPp), maxPp(maxPp)
{

}

std::string Move::getName() const
{
    return name;
}

int Move::getPp() const
{
    return pp;
}

int Move::getMaxPp() const
{
    return maxPp;
}

bool Move::use(Monster *user, Monster *target)
{
    if (pp > 0) {
        _use(user, target);
        pp--;
        return false;
    } else {
        // No more PP! :(
        return false;
    }
}