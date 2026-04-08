class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        res =[]
        q = [[0]]
        while q:
            path = q.pop(0)
            node = path[-1]
            if node == n-1:
                res.append(path)
            else:
                for ngh in graph[node]:
                    q.append(path+[ngh])
        return res
        