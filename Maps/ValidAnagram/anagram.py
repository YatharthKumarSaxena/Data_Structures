def isAnagram(s1, s2):
    if len(s1) != len(s2):
        return False

    mp = {}

    for ch in s1:
        mp[ch] = mp.get(ch, 0) + 1

    for ch in s2:
        if ch in mp:
            mp[ch] -= 1
            if mp[ch] == 0:
                del mp[ch]
        else:
            return False

    return True