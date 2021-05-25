//  HazelcastClient.cpp

#include "hazelcastclient.h"

HazelcastClient::HazelcastClient(std::string ip, std::string clusterName, int port)
{
  this->ip = ip;
  this->port = port;
  this->clusterName = clusterName;
  hazelcast::client::client_config config;
  config.set_cluster_name(this->clusterName).get_network_config().add_address({this->ip, this->port});
  hz.reset(new hazelcast::client::hazelcast_client(hazelcast::new_client(std::move(config)).get()));
  mapName = "map";
  map = hz->get_map(mapName).get();
}

std::vector<hazelcast::byte> HazelcastClient::Get(std::string key)
{
  return map->get<std::string, std::vector<hazelcast::byte>>(key).get().value();
}

std::string HazelcastClient::GetUrl() {
  return this->ip + ":" + std::to_string(this->port) + "/" + this->mapName;
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