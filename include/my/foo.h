/*
 * This is a example class for a C++ web project
 *
 */

#include <string>

namespace my
{
  class Foo
  {
    public:
      Foo()
        : intValue(0)
      { }

      int getIntValue() const
      { return intValue; }

      const std::string& getStringValue() const
      { return stringValue; }

      void setIntValue(int v)
      { intValue = v; }

      void addIntValue(int v)
      { intValue += v; }

      void setStringValue(const std::string& s)
      { stringValue = s; }

      // declare more Foo methods here
      // void f();

    private:
      int intValue;
      std::string stringValue;

  };

}
