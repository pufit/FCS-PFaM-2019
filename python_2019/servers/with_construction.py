def f(x: str):
    return x in ['a', 'ab', 'abbc', 'bb']


def g(x: str) -> bool:
    checked = set()
    stack = [x]

    while stack:
        elem = stack.pop()
        for i in range(1, len(x)):
            if f(elem[:i]) and elem not in checked:
                checked.add(elem[:i])
                stack.append(elem[i:])
        if f(elem):
            return True
    return False

print(g('aabbbc'))
