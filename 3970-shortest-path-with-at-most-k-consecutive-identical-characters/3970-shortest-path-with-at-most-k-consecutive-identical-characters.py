class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))

        dist = [[float('inf')] * (k+1) for _ in range(n)]

        xy = [(0, 0 ,1)]
        dist[0][1] = 0

        while xy:
            cost, u, count = heapq.heappop(xy)

            if cost != dist[u][count]:
                continue

            if u == n-1:
                return cost
            for v, w in graph[u]:
                new_count = count + 1 if labels[u] == labels[v] else 1

                if new_count > k:
                    continue
                
                new_cost = cost + w

                if new_cost < dist[v][new_count]:
                    dist[v][new_count] = new_cost

                    heapq.heappush(xy, (new_cost, v, new_count))

        return -1