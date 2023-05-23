class SetADT:
    def __init__(self):
        self.items = []

    def add(self, new_element):
        if new_element not in self.items:
            self.items.append(new_element)

    def remove(self, element):
        if element in self.items:
            self.items.remove(element)

    def contains(self, element):
        return element in self.items

    def size(self):
        return len(self.items)

    def iterator(self):
        return iter(self.items)

    def intersection(self, other_set):
        intersection_set = SetADT()
        for item in self.items:
            if other_set.contains(item):
                intersection_set.add(item)
        return intersection_set

    def union(self, other_set):
        union_set = SetADT()
        union_set.items = self.items.copy()
        for item in other_set.items:
            union_set.add(item)
        return union_set

    def difference(self, other_set):
        difference_set = SetADT()
        for item in self.items:
            if not other_set.contains(item):
                difference_set.add(item)
        return difference_set

    def is_subset(self, other_set):
        for item in self.items:
            if not other_set.contains(item):
                return False
        return True

set1 = SetADT()
set1.add(1)
set1.add(2)
set1.add(3)
iter = set1.iterator()
for ele in iter:
    print(ele)

set2 = SetADT()
set2.add(3)
set2.add(4)
set2.add(5)

print(set1.contains(2))  # Output: True
print(set1.size())  # Output: 3

intersection_set = set1.intersection(set2)
print(intersection_set.items)  # Output: [3]

union_set = set1.union(set2)
print(union_set.items)  # Output: [1, 2, 3, 4, 5]

difference_set = set1.difference(set2)
print(difference_set.items)  # Output: [1, 2]

print(set1.is_subset(set2))  # Output: False
