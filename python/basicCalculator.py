class Solution:
    def calculate(self, s: str) -> int:
        op = "+"
        st = []
        curr = 0
        s += "+"
        for ch in s:
            if ch.isdigit():
                curr = curr * 10 + int(ch)
            elif ch == " ":
                continue
            else:
                if op == "+":
                    st.append(curr)
                elif op == "-":
                    st.append(-curr)
                elif op == "*":
                    left = st.pop()
                    curr = left * curr
                    st.append(curr)
                elif op == "/":
                    left = st.pop()
                    curr = left / curr
                    st.append(int(curr))

                op = ch
                curr = 0

        res = 0
        while st:
            res += st.pop()
        return res
