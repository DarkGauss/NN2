
import os

TEST_FILE_DIR = "/TD2"
CWD = os.getcwd()
DEBUG = False

#os.system(./nn < TD2/newxor.in)
#os.system(cwd+"/nn <"+cwd+"/TD2/newxor.in)

import tempfile,os

#func not made by me to get output of running command
def read_cmd(cmd):
    ftmp = tempfile.NamedTemporaryFile(suffix='.out', prefix='tmp', delete=False)
    fpath = ftmp.name
    if os.name=="nt":
        fpath = fpath.replace("/","\\") # forwin
    ftmp.close()
    os.system(cmd + " > " + fpath)
    data = ""
    with open(fpath, 'r') as file:
        data = file.read()
        file.close()
    os.remove(fpath)
    return data

def get_names():
    names_list_1 = []
    names_list_2 = []
    TD2 = CWD + TEST_FILE_DIR
    for path, subdir, files in os.walk(TD2):
        for name in files:
            if "Iris" in name:
                names_list_2.append(name)
            else:
                names_list_1.append(name)
    return names_list_1 , names_list_2

def get_results(eta = 0.01, runs = 10000, v_low = 0.0, v_high = 1.0 , w_low = 0.0, w_high = 1.0):
    input_names_1 , input_names_2 = get_names()
    results_1 = []
    results_2 = []
    i = 0
    for name in input_names_1:
        sml_cmd = "./nn " +str(eta)+" "+str(runs)+" "+str(v_low)+" "+str(v_high)+" "+str(w_low)+" "+str(w_high)+" 0 <"+"./TD2/"+name
        cmd = CWD+"/nn " +str(eta)+" "+str(runs)+" "+str(v_low)+" "+str(v_high)+" "+str(w_low)+" "+str(w_high)+" 0 <"+CWD+"/TD2/"+name
        results_1.append(read_cmd(cmd))
        if DEBUG:
            print("Running {} on {} with results {}".format(sml_cmd,name,results_1[i]))
        i += 1
    i = 0
    for name in input_names_2:
        sml_cmd = "./nn " +str(eta)+" "+str(runs)+" "+str(v_low)+" "+str(v_high)+" "+str(w_low)+" "+str(w_high)+" 1 <"+"./TD2/"+name
        cmd = CWD+"/nn " +str(eta)+" "+str(runs)+" "+str(v_low)+" "+str(v_high)+" "+str(w_low)+" "+str(w_high)+" 1 <"+CWD+"/TD2/"+name
        results_2.append(read_cmd(cmd))
        if DEBUG:
            print("Running {} on {} with results {}".format(sml_cmd,name,results_2[i]))
        i += 1
    print("Params:")
    print("eta = {}, runs = {}, v_low = {}, v_high = {} , w_low = {}, w_high = {}".format(eta, runs, v_low, v_high, w_low, w_high))
    print(results_1, results_2)
    return results_1 , results_2

def get_results2():
    input_names_1 , input_names_2 = get_names()
    results_1 = []
    results_2 = []
    for name in input_names_1:
        cmd = CWD+"/nn" + " <"+ CWD+"/TD2/"+name
        results_1.append(read_cmd(cmd))
    for name in input_names_2:
        cmd = CWD+"/nnoneof "+ " <"+CWD+"/TD2/"+name
        results_2.append(read_cmd(cmd))

    print(results_1, results_2)
    return results_1 , results_2
"""
get_results(eta = 0.1 ,v_low = -1.0, v_high = 1.0, w_low = -2.0, w_high = 1.0)
get_results(eta = 0.1 ,v_low = -.5, v_high = .5, w_low = -0.5, w_high = 0.5)
get_results(eta = 0.1 ,v_low = 0, v_high = 1.0, w_low = 0, w_high = 1.0)
get_results(eta = 0.1 ,v_low = 0, v_high = .5, w_low = 0, w_high = 0.5)


get_results(eta = 0.05 ,v_low = -1.0, v_high = 1.0, w_low = -2.0, w_high = 1.0)
get_results(eta = 0.05 ,v_low = -.5, v_high = .5, w_low = -0.5, w_high = 0.5)
get_results(eta = 0.05 ,v_low = 0, v_high = 1.0, w_low = 0, w_high = 1.0)
get_results(eta = 0.05 ,v_low = 0, v_high = .5, w_low = 0, w_high = 0.5)

tuples = [(-a/10,b/10) for a in range(0,10) for b in range (0,11)]

"""
get_results2()