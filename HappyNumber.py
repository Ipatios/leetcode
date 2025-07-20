class Solution:
    def isHappy(self, n: int) -> bool:
        myDict = {}
        while n not in myDict:
            myDict[n] = True
            n = sum(int(i) ** 2 for i in str(n))
            if n == 1:
                return True

        if n in myDict:
            return False

        return False


def main():
    n = 2
    sol = Solution()
    print(sol.isHappy(n))


if __name__ == "__main__":
    main()
