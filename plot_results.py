import csv

import numpy as np
import matplotlib.pyplot as plt

files = ["in.csv", "out.csv"]


def read_data(file_path):
    data = []
    with open(file_path, "r") as f:
        reader = csv.reader(f)
        for line in reader:
            data.append(np.asarray([float(i) for i in line]))
    return np.asarray(data)


def main():
    fig, axs = plt.subplots(2, 1)
    in_data, out_data = [read_data(n) for n in files]
    axs[0].plot(in_data[:, 0])
    axs[1].plot(out_data[:, 0])

    plt.show()

if __name__ == "__main__":
    main()
