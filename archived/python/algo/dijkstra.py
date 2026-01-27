def find_lowest(costs):
    lowest = float("inf")  # 無限成本 == 無法抵達（未處理）
    lowest_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest and node not in processed:
            lowest = cost
            lowest_node = node
    return lowest_node


# Graph：圖表（類似地圖）
graph = {}
graph["a"] = {}
graph["a"]["fin"] = 1
graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5
graph["fin"] = {}

# Costs：成本
infinity = float("inf")  # 未處理節點的暫時成本（表示永遠無法抵達終點）
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity

# Parents：父節點
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None

# Processed：處理過的資料
processed = []

node = find_lowest(costs)

while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new = cost + neighbors[n]
        if costs[n] > new:
            costs[n] = new
            parents[n] = node
    processed.append(node)
    node = find_lowest(costs)  # f(x) = f(x) + 1
