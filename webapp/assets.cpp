////////////////////////////////////////////////////////////////////////
// assets.cpp
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

log_define("component.assets")

// <%pre>
#line 4 "assets.ecpp"

#include <czmq.h>
#include <cxxtools/split.h>

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

static tnt::ComponentFactoryImpl<_component_> Factory("assets");

static const char* rawData = "\024\000\000\000\025\000\000\0007\000\000\0008\000\000\000:\000\000\000\n        {\"outpu"
  "t\" : \"all assets\"}\n{}\n";

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
  log_trace("assets " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%args>
std::string asset_id = qparam.param("asset_id", ( request.getArg ("asset-id")));
  // </%args>

  // <%cpp>
  reply.out() << data[0]; // \n
#line 12 "assets.ecpp"

    printf("asset-id: %s", asset_id.c_str ());

    std::vector<std::string> items;
    std::vector<std::string>::iterator it;
    std::string response;

    if (asset_id.find(","))
        cxxtools::split("," , asset_id, std::back_inserter(items));

    printf("size of vec. %d\n", items.size());
    if (asset_id.empty ())

  reply.out() << data[1]; //         {"output" : "all assets"}\n
#line 26 "assets.ecpp"

    else
    {
        for (it = items.begin (); it != items.end (); ++it)
            response += "\"asset_id\" : \"" + *it + "\", \n";
    }

  reply.out() << data[2]; // {
#line 33 "assets.ecpp"
  reply.out() << ( response );
  reply.out() << data[3]; // }\n
  // <%/cpp>
  return HTTP_OK;
}

} // namespace
