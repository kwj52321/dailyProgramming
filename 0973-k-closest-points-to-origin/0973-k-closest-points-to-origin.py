class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        if len(points) == 1:
            return points

        mid = len(points) // 2
        left = self.kClosest(points[:mid], k)
        right = self.kClosest(points[mid:], k)
        merge = []
        i = j = 0
        while i<len(left) and j<len(right):
            l_dist = left[i][0]**2 + left[i][1]**2
            r_dist = right[j][0]**2 + right[j][1]**2
            if(l_dist <= r_dist):
                merge.append(left[i])
                i += 1
            else:
                merge.append(right[j])
                j += 1
        if i < len(left):
            merge.extend(left[i:])
            return merge[:k]
        elif j < len(right):
            merge.extend(right[j:])
            return merge[:k]
        else: 
            return merge[:k]


        