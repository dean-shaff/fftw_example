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

    in_data = in_data[:, 0] + 1j* in_data[:, 1]
    out_data = out_data[:, 0] + 1j* out_data[:, 1]

    axs[0].plot(np.real(in_data))
    # axs[1].plot((np.abs(out_data)**2)[255:][::-1])
    axs[1].plot((np.abs(out_data)**2)[:out_data.shape[0]//2])
    # axs[2].plot(np.angle(out_data))
    axs[1].set_xlabel("samples")
    # axs[2].set_xlabel("samples")

    fig.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()
