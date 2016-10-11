function standardOutput(value) {
    return value < 10 ? ("0" + value) : value
}
function currentDatetime() {
    var str
    var today = new Date()
     str = today.getFullYear()+'-'+standardOutput(today.getMonth())+'-'+standardOutput(today.getDay())+' '+standardOutput(today.getHours())+':'+standardOutput(today.getMinutes())+':'+standardOutput(today.getSeconds())
    return str
}
