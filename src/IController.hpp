#ifndef SRC_ICONTROLLER_HPP
#define SRC_ICONTROLLER_HPP

namespace src
{

class IController
{
public:
    virtual ~IController(){}
    virtual void execute() = 0;
};

} // namespace src

#endif // SRC_ICONTROLLER_HPP
