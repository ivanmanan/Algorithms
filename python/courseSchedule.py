class Solution:

    def dfs(self, course, prereqs_map, done, seen, res) -> bool:
        if course in done:
            # already handled this course
            return True
        if not prereqs_map[course]:
            # course has no dependency
            res.append(course)
            done.add(course)
            return True
        if course in seen:
            return False

        seen.add(course)
        for prereq in prereqs_map[course]:
            if not self.dfs(prereq, prereqs_map, done, seen, res):
                return False
        res.append(course)
        done.add(course)
        seen.remove(course)
        return True


    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        prereqs_map = defaultdict(list)

        for p in prerequisites:
            prereqs_map[p[0]].append(p[1])

        done = set()
        seen = set()
        res = []
        for i in range(numCourses):
            if not self.dfs(i, prereqs_map, done, seen, res):
                return []
        return res
