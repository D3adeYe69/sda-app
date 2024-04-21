function calculateLoan() {
    var price = parseFloat(document.getElementById('price').value);
    var bankChoice = parseInt(document.getElementById('bank').value);
    var loanType = parseInt(document.getElementById('loanType').value);
    var loanTermMonths = parseInt(document.getElementById('loanTerm').value);
    var totalLoan, monthlyPayment;

    // Perform AJAX request to send data to server and get loan calculation results
    var xhr = new XMLHttpRequest();
    xhr.open('POST', '/calculateLoan', true);
    xhr.setRequestHeader('Content-Type', 'application/json');
    xhr.onreadystatechange = function () {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            if (xhr.status === 200) {
                var loanDetails = JSON.parse(xhr.responseText);
                totalLoan = loanDetails.totalLoan;
                monthlyPayment = loanDetails.monthlyPayment;
                displayLoanDetails(totalLoan, monthlyPayment);
            } else {
                alert('Error: ' + xhr.statusText);
            }
        }
    };
    var data = {
        price: price,
        bankChoice: bankChoice,
        loanType: loanType,
        loanTermMonths: loanTermMonths
    };
    xhr.send(JSON.stringify(data));
}

function displayLoanDetails(totalLoan, monthlyPayment) {
    var resultDiv = document.getElementById('result');
    resultDiv.innerHTML = '<h3>Loan Details:</h3>' +
        '<p>Total Loan Amount: $' + totalLoan.toFixed(2) + '</p>' +
        '<p>Monthly Payment: $' + monthlyPayment.toFixed(2) + '</p>';
}
