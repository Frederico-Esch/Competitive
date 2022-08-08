import matplotlib.pyplot as plt
from pathlib import Path

import numpy as np
import pandas as pd

files = Path(".").glob("[!C]*.txt")

for file in files:
    result_name = file.stem
    cols = ["in use bytes", "max mmap bytes"]
    result = pd.DataFrame()
    with open(file, "r") as src:
        data = "".join(src.readlines()).split("Arena 0:")
        for d in data:
            d = d.split("\n")
            d = {x.split("=")[0].strip(): x.split("=")[1].split() for x in d if len(x.split("=")) > 1}
            result = pd.concat([result, pd.DataFrame(d)],  ignore_index=1)

        result = result[cols]
        result = result.astype(int)

        for col in result.columns:
            plt.title(result_name+"_"+col)
            plt.plot(np.arange(0, result[col].size, 1), result[col].values)
            plt.savefig(result_name+"_"+col+".jpg")
            plt.clf()
