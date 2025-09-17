def min_bracket_reversals(expr):
    if len(expr) % 2 != 0:
        return -1
    stack = []
    for char in expr:
        if char == '{':
            stack.append(char)
        else:
            if stack and stack[-1] == '{':
                stack.pop()
            else:
                stack.append(char)
    return (len(stack) // 2) + (stack.count('{') % 2)