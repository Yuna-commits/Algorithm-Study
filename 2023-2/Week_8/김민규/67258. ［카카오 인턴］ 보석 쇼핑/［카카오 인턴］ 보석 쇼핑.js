// function solution(gems) {
//     const count = new Set(gems).size;
//     const map = new Map();
//     let result = [1, gems.length];

//     gems.forEach((gem, i) => {
//         map.set(gem, i);

//         if (map.size === count) {
//             const start = Math.min(...map.values()) + 1;
//             const end = i + 1;
//             if ((end - start) < (result[1] - result[0])) {
//                 result = [start, end];
//             }
//         }
//     });

//     return result;
// }

function solution(gems) {
    const count = new Set(gems).size
    const map = new Map()
    const result = []
    gems.forEach((gem,i)=> {
        map.delete(gem)
        map.set(gem,i)
        if(map.size === count){
            result.push([map.values().next().value+1, i+1])
        }
    })
    return result.sort((a,b)=> (a[1]-a[0])-(b[1]-b[0]))[0] 
}