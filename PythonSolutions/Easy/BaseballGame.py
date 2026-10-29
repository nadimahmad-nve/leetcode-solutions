class Solution:
    def calPoints(self, operations: list[str]) -> int:
        record = []

        for operation in operations:
            if operation == '+': 
                x = record[-1]
                y = record[-2]
                record.append(x+y)
            elif operation == 'D':
                record.append(record[-1]*2)
            elif operation == 'C':
                record.pop()
            else: 
                # Number found
                record.append(int(operation))
        
        if len(record) > 0: 
            total = 0 
            for i in range(len(record)):
                total += record[i]
            
            return total
        else:
            return 0 
        