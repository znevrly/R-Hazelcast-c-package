# build package inside folder

    R CMD INSTALL .

# usage in R

    library(HazelcastClient)
    new(HazelcastClient, ip = "10.30.100.180", clusterName = "DEV")


