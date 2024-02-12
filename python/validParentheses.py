class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        for ch in s:
            if ch == "(" or ch == "{" or ch == "[":
                st.append(ch)
            elif ch == ")":
                if not st:
                    return False
                top = st.pop()
                if top != "(":
                    return False
            elif ch == "}":
                if not st:
                    return False
                top = st.pop()
                if top != "{":
                    return False
            elif ch == "]":
                if not st:
                    return False
                top = st.pop()
                if top != "[":
                    return False
            else:
                continue

        if st:
            return False
        return True
