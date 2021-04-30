//  HazelcastClient.cpp

#include "hazelcastClient.h"

HazelcastClient::HazelcastClient(std::string ip, std::string clusterName, int port)
{
  hazelcast::client::client_config config;
  config.set_cluster_name(clusterName).get_network_config().add_address({ip, port});
  hz.reset(new hazelcast::client::hazelcast_client(hazelcast::new_client(std::move(config)).get()));
  mapName = "map";
  map = hz->get_map(mapName).get();
}

std::vector<hazelcast::byte> HazelcastClient::Get(std::string key)
{
  return map->get<std::string, std::vector<hazelcast::byte>>(key).get().value();
}

void HazelcastClient::Put(std::string key, std::vector<hazelcast::byte> value)
{
  map->put<std::string, std::vector<hazelcast::byte>>(key, value).get();
}

void HazelcastClient::SetMap(std::string mapName)
{
  this->mapName = mapName;
  map = hz->get_map(this->mapName).get();
}