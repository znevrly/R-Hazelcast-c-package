//  HazelcastClient.cpp

#include "hazelcastClient.h"

HazelcastClient::HazelcastClient(std::string ip, std::string clusterName, int port)
{
  hazelcast::client::client_config config;
  config.set_cluster_name(clusterName).get_network_config().add_address({ip, port});
  hz.reset(new hazelcast::client::hazelcast_client(hazelcast::new_client(std::move(config)).get()));
  this->mapName = "map";
}

std::vector<hazelcast::byte> HazelcastClient::Get(std::string key)
{
  auto map = hz->get_map(this->mapName).get();
  return map->get<std::string, std::vector<hazelcast::byte>>(key).get();
}

void HazelcastClient::Put(std::string key, std::vector<hazelcast::byte> value)
{
  auto map = hz->get_map(this->mapName).get();
  map->put<std::string, std::vector<hazelcast::byte>>(key, value).get();
}

void HazelcastClient::SetMap(std::string mapName)
{
  this->mapName = mapName;
}