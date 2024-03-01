from calc_checking import check_results, read_json, read_matrix, write_to_file, draw_graph

if __name__ == "__main__":
    sizes = [100, 250, 300, 500, 750, 900, 1000]
    times = []
    for size in sizes:
        size, time = read_json(f'matrix_{size}.json')
        times.append(time)
        m1 = read_matrix('data', f'matrix_1_{size}.txt')
        m2 = read_matrix('data', f'matrix_2_{size}.txt')
        res = read_matrix(f'results/result_matrix', f'result_matrix_{size}.txt')
        write_to_file(size, check_results(m1, m2, res))
    draw_graph(sizes, times)