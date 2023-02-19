import csv
import sys

from queue import Queue

# Function to load data from the CSV file
def load_data(filename):
    data = {}
    with open(filename, "r") as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            if row[0] not in data:
                data[row[0]] = set()
            data[row[0]].add(row[1])
            if row[1] not in data:
                data[row[1]] = set()
            data[row[1]].add(row[0])
    return data

# Function to find the shortest path between two actors using BFS
def bfs(start, end, data):
    visited = set()
    queue = Queue()
    queue.put((start, 0))
    while not queue.empty():
        actor, degree = queue.get()
        if actor == end:
            return degree
        visited.add(actor)
        for neighbor in data[actor]:
            if neighbor not in visited:
                queue.put((neighbor, degree + 1))
    return None

# Main function
def main():

    data = load_data('small.csv')
    start = "Bill Paxton"
    end = "Robin Wright"
    degree = bfs(start, end, data)
    if degree is None:
        print("No connection found")
    else:
        print(f"{start} and {end}: Degree of Separation = {degree} ")

if __name__ == "__main__":
    main()
