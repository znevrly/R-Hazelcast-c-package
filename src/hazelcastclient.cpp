//  HazelcastClient.cpp

#include "hazelcastclient.h"

HazelcastClient::HazelcastClient(std::string ip, std::string clusterName, int port)
{
  this->ip = ip;
  this->port = port;
  this->clusterName = clusterName;
  hazelcast::client::client_config config;
  config.set_cluster_name(this->clusterName).get_network_config().add_address({this->ip, this->port});
  config.get_connection_strategy_config().get_retry_config().set_cluster_connect_timeout(std::chrono::seconds(30));
  this->hz.reset(new hazelcast::client::hazelcast_client(hazelcast::new_client(std::move(config)).get()));
  this->mapName = "map";
  this->verboseMode = false;
  this->map = this->hz->get_map(mapName).get();
}

std::vector<hazelcast::byte> HazelcastClient::Get(std::string key)
{
  if (!map->contains_key(key).get()) {
    throw std::invalid_argument("HZ error: can not find key: " + key + " at " + GetUrl());
  }
  if (this->verboseMode) {
    std::cout << "Successfully fetched HZ value: " << this->mapName << "/" << key << "\n";
  }  
  return this->map->get<std::string, std::vector<hazelcast::byte>>(key).get().value();
}

std::string HazelcastClient::GetUrl() {
  return this->ip + ":" + std::to_string(this->port) + "/" + this->mapName;
}

void HazelcastClient::Put(std::string key, std::vector<hazelcast::byte> value)
{
  this->map->put<std::string, std::vector<hazelcast::byte>>(key, value).get();
}

void HazelcastClient::SetMap(std::string mapName)
{
  this->mapName = mapName;
  this->map = hz->get_map(this->mapName).get();
}

void HazelcastClient::SetVerboseMode(bool verboseMode)
{
  this->verboseMode = verboseMode;
}