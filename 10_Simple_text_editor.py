def simple_text_editor(operations):
    s = ""
    history = []
    for op in operations:
        if op[0] == '1':
            history.append(s)
            s += op[1]
        elif op[0] == '2':
            history.append(s)
            k = int(op[1])
            s = s[:-k]
        elif op[0] == '3':
            k = int(op[1])
            print(s[k-1])
        elif op[0] == '4':
            s = history.pop()