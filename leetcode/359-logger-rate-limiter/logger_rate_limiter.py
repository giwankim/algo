import collections


class Logger:
    def __init__(self):
        self.table = {}

    def shouldPrintMessage(self, timestamp, message):
        if message in self.table and self.table[message] > timestamp - 10:
            return False
        self.table[message] = timestamp
        return True


if __name__ == "__main__":
    logger = Logger()
    assert logger.shouldPrintMessage(1, "foo") == True
    assert logger.shouldPrintMessage(2, "bar") == True
    assert logger.shouldPrintMessage(3, "foo") == False
    assert logger.shouldPrintMessage(8, "bar") == False
    assert logger.shouldPrintMessage(10, "foo") == False
    assert logger.shouldPrintMessage(11, "foo") == True
