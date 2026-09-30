class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == "(" or c == "[" or c == "{":
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False 

                onTop = stack[-1]
                if onTop == "(" and c == ")" or onTop == "[" and c == "]" or onTop == "{" and c == "}":
                    # Valid combination
                    stack.pop()
                else:
                    # Mismatched brackets
                    return False
        
        if len(stack) == 0:
            return True
        else:
            return False