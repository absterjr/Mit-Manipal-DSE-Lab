import csv

# Load the data from the CSV file into a dictionary
def load_data(filename):
    data = {}
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            actor = row[0]
            movie = row[1]
            if actor not in data:
                data[actor] = set()
            data[actor].add(movie)
            if movie not in data:
                data[movie] = set()
            data[movie].add(actor)
    return data

# Find the shortest path between two actors using depth first search
def dfs(data, start, end, path=None):
    if path is None:
        path = [start]
    if start == end:
        return path
    for actor in data[start]:
        if actor not in path:
            new_path = dfs(data, actor, end, path + [actor])
            if new_path is not None:
                return new_path
    return None

# Load the data from the CSV file
data = load_data('small.csv')

# Find the shortest path between Kevin Bacon and Tom Hanks
path = dfs(data, 'Kevin Bacon', 'Tom Cruise')

# Print the shortest path
if path is None:
    print("No path found")
else:
    print(" -> ".join(path))
