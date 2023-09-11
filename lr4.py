import math

class CubicEquationSolver:
    def solve(self, a, b, c, d):
        D = 18 * a * b * c * d - 4 * b**3 * d + b**2 * c**2 - 4 * a * c**3 - 27 * a**2 * d**2
        if D > 0:
            Q = (3 * a * c - b**2) / (9 * a**2)
            R = (9 * a * b * c * d - 2 * b**3 * c + 27 * a**2 * d**2) / (54 * a**3)
            theta = math.acos(R / math.sqrt(-Q**3))
            x1 = -2 * math.sqrt(-Q) * math.cos(theta / 3) - (b / (3 * a))
            x2 = -2 * math.sqrt(-Q) * math.cos((theta + 2 * math.pi) / 3) - (b / (3 * a))
            x3 = -2 * math.sqrt(-Q) * math.cos((theta + 4 * math.pi) / 3) - (b / (3 * a))
            return [x1, x2, x3]
        elif D == 0:
            Q = (3 * a * c - b**2) / (9 * a**2)
            x1 = -2 * math.sqrt(-Q) - (b / (3 * a))
            x2 = math.sqrt(-Q) - (b / (3 * a))
            return [x1, x2]
        else:
            return []

# Пример использования:
solver = CubicEquationSolver()
a, b, c, d = 1, -6, 11, -6
solutions = solver.solve(a, b, c, d)
print(solutions)
 
