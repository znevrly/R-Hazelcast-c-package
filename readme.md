# Build package (relative path)

    R CMD INSTALL .

# Usage in R

    library(HazelcastClient)
    hz = new(HazelcastClient, ip = "10.30.100.180", clusterName = "DEV")


