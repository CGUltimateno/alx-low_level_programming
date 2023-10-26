#!/usr/bin/python3
"""Defines a function that returns the perimeter of an island"""



def island_perimeter(grid):
    """Returns the perimeter of an island"""
    rows, cols = 0, 0
    perim = 0

    if grid is None or grid == [] or len(grid) == 0 or len(grid[0]) == 0:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    for row in range(0, rows, 1):
        for col in range(0, cols, 1):
            if grid[row][col] == 1:
                perim += 4
                if row > 0 and grid[row - 1][col] == 1:
                    perim -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    perim -= 2
    return perim
