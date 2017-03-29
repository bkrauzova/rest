////////////////////////////////////////////////////////////////////////
// rest.cpp
// generated with ecppc
//

#include <tnt/ecpp.h>
#include <tnt/convert.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>
#include <tnt/httpheader.h>
#include <tnt/http.h>
#include <tnt/data.h>
#include <tnt/componentfactory.h>
#include <cxxtools/log.h>
#include <stdexcept>

log_define("component.rest")

// <%pre>
#line 1 "rest.ecpp"

// put your includes here
#include <my/foo.h>

// </%pre>

namespace
{
class _component_ : public tnt::EcppComponent
{
    _component_& main()  { return *this; }

  protected:
    ~_component_();

  public:
    _component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl);

    unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
};

static tnt::ComponentFactoryImpl<_component_> Factory("rest");

static const char* rawData = "\024\000\000\000p\000\000\000\200\000\000\000\312\000\000\000N\001\000\000<html>\n <head>"
  "\n  <title>ecpp-application rest</title>\n </head>\n <body>\n  <h1>rest</h1>\n  <p></p>\n  <p>Value=</p>\n\n  <form m"
  "ethod=\"post\">\n   <input type=\"text\" name=\"intValue\" value=\"\">\n   <input type=\"submit\" name=\"add\" value="
  "\"add\">\n   <input type=\"submit\" name=\"reset\" value=\"reset\">\n  </form>\n\n </body>\n</html>\n\n";

// <%shared>
// </%shared>

// <%config>
// </%config>

#define SET_LANG(lang) \
     do \
     { \
       request.setLang(lang); \
       reply.setLocale(request.getLocale()); \
     } while (false)

_component_::_component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl)
  : EcppComponent(ci, um, cl)
{
  // <%init>
  // </%init>
}

_component_::~_component_()
{
  // <%cleanup>
  // </%cleanup>
}

unsigned _component_::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
{
  log_trace("rest " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%args>
int intValue = qparam.has("intValue") ? tnt::stringToWithDefault<int>(qparam.param("intValue"), ( 0), reply.out().getloc()) : ( 0);
bool add = tnt::stringTo<bool>("add", "bool", qparam.param("add"), reply.out().getloc());
bool reset = tnt::stringTo<bool>("reset", "bool", qparam.param("reset"), reply.out().getloc());
  // </%args>

#line 17 "rest.ecpp"
  typedef my::Foo foo_type;
  TNT_SESSION_COMPONENT_VAR(foo_type, foo, "my::Foo foo", ());   // <%session> my::Foo foo
  // <%cpp>
#line 20 "rest.ecpp"


  // put your C++ code here

  if (add)
  {
    log_debug("add");
    foo.addIntValue(intValue);
  }

  if (reset)
  {
    log_debug("reset");
    foo.setIntValue(0);
  }

  foo.setStringValue("Hello world!");



  reply.out() << data[0]; // <html>\n <head>\n  <title>ecpp-application rest</title>\n </head>\n <body>\n  <h1>rest</h1>\n  <p>
#line 46 "rest.ecpp"
  reply.sout() << ( foo.getStringValue() );
  reply.out() << data[1]; // </p>\n  <p>Value=
#line 47 "rest.ecpp"
  reply.sout() << ( foo.getIntValue() );
  reply.out() << data[2]; // </p>\n\n  <form method="post">\n   <input type="text" name="intValue" value="
#line 50 "rest.ecpp"
  reply.sout() << (intValue);
  reply.out() << data[3]; // ">\n   <input type="submit" name="add" value="add">\n   <input type="submit" name="reset" value="reset">\n  </form>\n\n </body>\n</html>\n\n
#line 58 "rest.ecpp"
   return DECLINED;

  // <%/cpp>
  return HTTP_OK;
}

} // namespace
