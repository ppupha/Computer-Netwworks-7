import sys
import email, smtplib, ssl
import time
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

def send_mail():
    global subject, body, sender_email, receiver_email, password, filename, c
    # Create a multipart message and set headers
    message = MIMEMultipart()
    message["From"] = sender_email
    message["To"] = receiver_email
    message["Subject"] = subject
    #message["Bcc"] = receiver_email  # Recommended for mass emails

    # Add body to email
    message.attach(MIMEText(body, "plain"))

    try:

        # Open PDF file in binary mode
        with open(filename, "rb") as attachment:
            # Add file as application/octet-stream
            # Email client can usually download this automatically as attachment
            part = MIMEBase("application", "octet-stream")
            part.set_payload(attachment.read())

        # Encode file in ASCII characters to send by email    
        encoders.encode_base64(part)

        # Add header as key/value pair to attachment part
        part.add_header(
            "Content-Disposition",
            f"attachment; filename= {filename}",
        )

        # Add attachment to message and convert message to string
        message.attach(part)
    except:
        if c == None:
            print("File [{}] not Found".format(filename))
            c = input("Send Mail without file?[Y/N]")
        if (c == 'Y' or c == 'y'):
            None
        else:
            exit(-1)

        
    text = message.as_string()
    # Log in to server using secure context and send email
    context = ssl.create_default_context()
    with smtplib.SMTP_SSL("smtp.gmail.com", 465, context = context) as server:
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, text)
        server.quit()


if __name__ == "__main__":
    try:
        ar = sys.argv
        receiver_email = ar[1]
        sender_email = ar[2]
        password = ar[3]
        subject = "An email with attachment from Python"
        body = input("Input Email Message")
        filename = input("File Name: ")
        print("Input Time interval:")
        h = int(input("Input Hour"))
        m = int(input("Input Minute"))
        s = int(input("Input Second"))
        time_interval = s + m * 60 + h * 3600
    except:
        exit(-1)
    c = None
    n = 5
    for i in range(n):
        send_mail()
        time.sleep(time_interval)

    
