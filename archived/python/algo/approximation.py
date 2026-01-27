"""
what this does: you want to find the best way to colaborate with the least amount of stations
while covering all the cities requested

what is learned here:
    * sets
    * hash tables in action
    * syntax: for key, value in dictionary:
"""

# NOTE: although this algorithm compared to the greedy algorithm produces a more accurate result,
# but is much less efficient. Keep in mind that greedy algorithm is preferred when solving problems.

cities_needed = set(["taipei", "taichung", "taoyuan", "nantou", "hualian"])

stations = {}
stations["kone"] = set(["hsinchu", "taipei", "hualian"])
stations["ktwo"] = set(["taipei", "taoyuan", "yilan"])
stations["kthree"] = set(["kaoshung", "pingtung", "taitung"])
stations["kfour"] = set(["nantou", "taichung", "taipei", "hualian", "yunlin"])
stations["kfive"] = set(["taipei", "hualian", "yilan"])
stations["kbroke"] = set([])

results = set()
best_result = None
cities_covered = set()
while cities_needed:
    for station, cities_for_station in stations.items():
        covered = cities_needed & cities_for_station  # set intersection of the sets

        if len(covered) > len(cities_covered):  # if true overrides old record
            best_result = station
            cities_covered = covered

    results.add(best_result)
    cities_needed -= cities_covered

print(results)
