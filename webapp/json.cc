#include <string>
#include <cxxtools/jsonserializer.h>
#include <cxxtools/serializationinfo.h>
#include <sstream>


// groups, parents
struct asset_short
{
    std::string id;
    std::string name;
    std::string subtype;
    std::string type;
};


struct assets
{
    // asset_types
    std::string id;
    std::string name;

    // particular asset
    std::string status;
    std::string subtype;
    std::string priority;
    std::string location;
    std::vector <asset_short> groups;
    std::vector <asset_short> exts;
    std::vector <asset_short> parents;
    std::vector <std::string> computed;

    // for ext vector of "key" : "value"
    std::vector <std::string> keys;
    std::vector <std::string> values;
};

struct powerchains
{
    std::string src_id;
    std::string dest_id;
    std::string src_socket;
    std::string dest_socket;
};


// topology for asset_types, powerchains
struct topology
{
    std::vector <assets> v_devices;
    std::vector <asset_short> v_devices_short;
    std::vector <powerchains> v_powerchains;
    std::string asset_type;
};

void operator<<= (cxxtools::SerializationInfo& si, const asset_short& asset)
{
    si.addMember("id") <<= asset.id;
    si.addMember("name") <<= asset.name;
    si.addMember("type") <<= asset.type;
    si.addMember("subtype") <<= asset.subtype;

}

void operator<<= (cxxtools::SerializationInfo& si, const assets& asset)
{

    si.addMember("id") <<= asset.id;
    si.addMember("name") <<= asset.name;
    si.addMember("status") <<= asset.status;
    si.addMember("subtype") <<= asset.subtype;

    if (!asset.keys.empty ())
    {
        si.addMember("priority") <<= asset.priority;
        si.addMember("location") <<= asset.location;

        si.addMember("groups") <<= asset.groups;
        si.addMember("ext") <<= asset.exts;
        si.addMember("computed") <<= asset.computed;
    }
}

void operator<<= (cxxtools::SerializationInfo& si, const powerchains& powerchain)
{
    si.addMember("src_id") <<= powerchain.src_id;
    si.addMember("dest_id") <<= powerchain.dest_id;
    si.addMember("src_socket") <<= powerchain.src_socket;
    si.addMember("dest_socket") <<= powerchain.dest_socket;
}

void operator<<= (cxxtools::SerializationInfo& si, const topology& topo)
{
    if (!topo.v_devices.empty ())
        si.addMember (topo.asset_type) <<= topo.v_devices;
    if (!topo.v_devices_short.empty ())
        si.addMember (topo.asset_type) <<= topo.v_devices_short;
    if (!topo.v_powerchains.empty ())
        si.addMember("powerchain") <<= topo.v_powerchains;
}
/*
void
create_response (const std::string asset_id,
                 const std::string asset_name,
                 std::vector <assets>&  v_devices,
                 std::vector <powerchains>& v_powerchains)
{
    assets asset;
    powerchains powerchain;

    asset.id = asset_id;
    asset.name = asset_name;
    v_devices.push_back (asset);

    if (!call_type.compare ("pc"))
    {
        powerchain.src_id = asset_id;
        powerchain.dest_id = "epdu-2";
        powerchain.src_socket = "1";
        powerchain.dest_socket = "2";
        v_powerchains.push_back (powerchain);
    }
}
*/
void
asset_generator (std::string asset_type,
                 std::string asset_id,
                 std::vector <assets> &v_devices,
                 std::vector <asset_short> &v_devices_short,
                 std::vector <powerchains> &v_powerchains)
{
    asset_short asset_short;
    assets asset;
    powerchains powerchain;

    if (!asset_type.empty ())
    {

        for (int i = 1; i <= 5; ++i)
        {
            std::string id = asset_type + "-" + std::to_string (i);
            std::string name = "asset_name" + std::to_string (i);

            asset_short.id = id;
            asset_short.name = name;
            v_devices_short.push_back (asset_short);
        }

        return;
    }

    // TODO exts
    if (!asset_id.empty ())
    {
        std::string id = asset_type + "-" + id;
        std::string name = "asset_name" + id;

        asset.id = id;
        asset.name = name;
        asset.status = "active";
        asset.subtype = "my-subtype";
        asset.priority = "P1";
        asset.location = "DC01";

        // groups
        asset_short.id = "10";
        asset_short.name = "GRP.BIOS";
        asset.groups.push_back (asset_short);
        v_devices.push_back (asset);
        return;
    }

    // power chain
    if (asset_id.empty () && asset_type.empty ())
    {
        powerchain.src_id = asset_id;
        powerchain.dest_id = "epdu-2";
        powerchain.src_socket = "1";
        powerchain.dest_socket = "2";
        v_powerchains.push_back (powerchain);
    }
    return;
}

void
jsonify (std::string &asset_id, std::string &asset_type, std::ostream &out)
{
    topology topo;
    std::vector <assets> v_devices;
    std::vector <asset_short> v_devices_short;
    std::vector <powerchains> v_powerchains;

    asset_generator (asset_type, asset_id, v_devices, v_devices_short, v_powerchains);

    topo.asset_type = asset_type;

    topo.v_devices_short = std::move (v_devices_short);
    topo.v_devices = std::move (v_devices);
    topo.v_powerchains = std::move (v_powerchains);

    cxxtools::JsonSerializer serializer (out);
    serializer.serialize(topo).finish();


}
