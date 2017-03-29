////////////////////////////////////////////////////////////////////////
// first.cpp
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

log_define("component.first")

// <%pre>
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

static tnt::ComponentFactoryImpl<_component_> Factory("first");

static const char* rawData = "\010\000\000\000\201\000\000\000<html>\n <head>\n  <title>ecpp-application rest</title>\n"
  " </head>\n <body>\n  <h1>rest</h1>\n\n  <p>first</p>\n </body>\n</html>\n\n";

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
  log_trace("first " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
  reply.out() << data[0]; // <html>\n <head>\n  <title>ecpp-application rest</title>\n </head>\n <body>\n  <h1>rest</h1>\n\n  <p>first</p>\n </body>\n</html>\n\n
#line 12 "first.ecpp"
 return DECLINED;

  // <%/cpp>
  return HTTP_OK;
}

} // namespace
